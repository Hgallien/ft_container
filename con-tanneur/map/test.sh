#!/bin/bash
./map
diff std_out mine_out > diff
cat diff
