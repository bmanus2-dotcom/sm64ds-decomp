import importlib
import pathlib
import sys
import tempfile
import unittest

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
worklist = importlib.import_module("worklist")


class TargetIsDoneTest(unittest.TestCase):
    def setUp(self):
        self.temp_dir = tempfile.TemporaryDirectory()
        self.original_src = worklist.REPO_SRC
        worklist.REPO_SRC = pathlib.Path(self.temp_dir.name)

    def tearDown(self):
        worklist.REPO_SRC = self.original_src
        self.temp_dir.cleanup()

    def test_ledger_entry_is_done(self):
        done = {("arm9", 0x02001234)}
        self.assertTrue(
            worklist.target_is_done(done, "arm9", 0x02001234, "func_02001234")
        )

    def test_c_source_is_done_when_ledger_lags(self):
        (worklist.REPO_SRC / "func_02001234.c").write_text(
            "void func_02001234(void) {}\n", encoding="utf-8"
        )
        self.assertTrue(
            worklist.target_is_done(set(), "arm9", 0x02001234, "func_02001234")
        )

    def test_cpp_source_is_done_when_ledger_lags(self):
        (worklist.REPO_SRC / "func_02001234.cpp").write_text(
            "//cpp\nvoid func_02001234() {}\n", encoding="utf-8"
        )
        self.assertTrue(
            worklist.target_is_done(set(), "arm9", 0x02001234, "func_02001234")
        )

    def test_missing_source_and_ledger_entry_remains_available(self):
        self.assertFalse(
            worklist.target_is_done(set(), "arm9", 0x02001234, "func_02001234")
        )


if __name__ == "__main__":
    unittest.main()
