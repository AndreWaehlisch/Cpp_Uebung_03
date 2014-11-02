set terminal postscript eps
set output 'werte.eps'

set xlabel 'm'
set ylabel 'IMF'
set title 'Inital Mass Function'

set logscale x
set logscale y

plot 'werte.txt' u 1:2 w l