#!/bin/bash
./vector
diff std_out mine_out > diff
cat diff
