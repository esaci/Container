#!/usr/bin/zsh
make -s fclean && make -s TESTER="1" NAMESPACE="ft"
echo "Timing for Tester 1, NAMESPACE FT"
time ./container 2> logft.txt
echo "\n\n"
make -s fclean && make -s TESTER="1" NAMESPACE="std"
echo "Timing for Tester 1, NAMESPACE STD"
time ./container 2> logstd.txt

diff logft.txt logstd.txt
echo "\n\n\n\n"

make -s fclean && make -s TESTER="2" NAMESPACE="ft"
echo "Timing for Tester 2, NAMESPACE FT"
time ./container 2> logft.txt
echo "\n\n"
make -s fclean && make -s TESTER="2" NAMESPACE="std"
echo "Timing for Tester 2, NAMESPACE STD"
time ./container 2> logstd.txt

diff logft.txt logstd.txt
