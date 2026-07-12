"""Canonical (module, addr) <-> current symbol name resolver.

The per-module symbol tables (config/arm9/**/symbols.txt, read via sweep.funcs) are the
single source of truth for a function's CURRENT name. Stored snapshots -- most notably
nearmiss/db.jsonl -- keep whatever name a record had when it was written, which goes
stale the instant a symbol import renames a `func_ADDR` placeholder to a real symbol
(`_ZN12PiranhaPlant13InitResourcesEv`, `Foo_Spawn`, ...).

Anything that joins a stored record back to the live world must key by (module, addr)
and resolve the display name through here -- never trust the stored name. Keying by name
silently misclassifies every renamed function (e.g. a matched func reads as "still a
near-miss", or an attempted func reads as "fresh").

Both directions share one lazily-built index, so importing this is cheap until first use.
"""
import modules as MOD
import sweep

_BY_ADDR = None   # (label, addr_int) -> current name
_BY_NAME = None   # current name -> (label, addr_int, size)


def _build():
    global _BY_ADDR, _BY_NAME
    if _BY_ADDR is not None:
        return
    _BY_ADDR, _BY_NAME = {}, {}
    for mod in MOD.modules():
        label = "arm9" if mod["name"] == "main" else mod["name"]
        for fn, addr, size in sweep.funcs(mod):
            _BY_ADDR[(label, addr)] = fn
            _BY_NAME[fn] = (label, addr, size)


def _addr_int(addr):
    return int(addr, 0) if isinstance(addr, str) else addr


def name_at(module, addr):
    """Current symbol name at (module, addr), or None if no arm function lives there.
    `addr` may be an int or a hex string ("0x0212feb4")."""
    _build()
    return _BY_ADDR.get((module, _addr_int(addr)))


def addr_of(name):
    """(module, addr_int, size) for a current symbol name, or None."""
    _build()
    return _BY_NAME.get(name)
