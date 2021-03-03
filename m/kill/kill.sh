ps ax | grep $1 > w
./kill $1
#rm w