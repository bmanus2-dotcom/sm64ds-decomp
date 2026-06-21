#!/bin/bash
# Launch N parallel near-miss cruncher shards (local, free). They share the DB safely
# via a cross-process lock and partition the work by --shard, so no two grind the same
# function. Usage: crunch_all.sh [N_shards] [secs_per_func] [max_div] [jobs_per_shard]
cd "$(dirname "$0")/../.."
N=${1:-4}; SECS=${2:-180}; MAXDIV=${3:-12}; J=${4:-2}
echo "launching $N shards, ${SECS}s/func, div<=${MAXDIV}, -j${J} each ($((N*J)) threads)"
pids=""
for i in $(seq 0 $((N-1))); do
  python tools/permuter/crunch.py --shard "$i/$N" --secs "$SECS" --max-div "$MAXDIV" -j "$J" --loop &
  pids="$pids $!"
done
wait $pids
echo "all shards finished a full pass with no new progress."
