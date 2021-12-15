#!/bin/bash
./stack
diff std_out mine_out > diff
cat diff
