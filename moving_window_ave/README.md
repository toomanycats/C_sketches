# Moving Average
I'd like to use a uC to capture an analog signal and do some basic DSP.
This is a moving window average (256 points wide) that uses the Donald Knuth method of
recursive average computation extended to a moving window.

The Makefile has a *plot* command which uses `gnuplot` to create visualization.
Otherwise the binary output `filter` will print the test input and output to `stdout`.

![sample plot](./sample_plot.jpg)

