set output 'werte.png'

set xlabel 'm'
set ylabel 'IMF'
set title 'Inital Mass Function'

set logscale x
set logscale y

plot 'data.txt' u 1:2 w l