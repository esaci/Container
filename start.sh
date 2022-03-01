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
echo "\n\n\n\n"

make -s fclean && make -s TESTER="3" NAMESPACE="ft"
echo "Timing for Tester 3, NAMESPACE FT"
time ./container 2> logft.txt
echo "\n\n"
make -s fclean && make -s TESTER="3" NAMESPACE="std"
echo "Timing for Tester 3, NAMESPACE STD"
time ./container 2> logstd.txt

diff logft.txt logstd.txt
echo "\n\n\n\n"

make -s fclean && make -s TESTER="4" NAMESPACE="ft"
echo "Timing for Tester 4, NAMESPACE FT"
time ./container 2> logft.txt
echo "\n\n"
make -s fclean && make -s TESTER="4" NAMESPACE="std"
echo "Timing for Tester 4, NAMESPACE STD"
time ./container 2> logstd.txt

diff logft.txt logstd.txt

make -s fclean && make -s TESTER="5" NAMESPACE="ft"
echo "Timing for Tester 5, NAMESPACE FT"
time ./container 2> logft.txt
echo "\n\n"
make -s fclean && make -s TESTER="5" NAMESPACE="std"
echo "Timing for Tester 5, NAMESPACE STD"
time ./container 2> logstd.txt

diff logft.txt logstd.txt

make -s fclean && make -s TESTER="6" NAMESPACE="ft"
echo "Timing for Tester 6, NAMESPACE FT"
time ./container 2> logft.txt
echo "\n\n"
make -s fclean && make -s TESTER="6" NAMESPACE="std"
echo "Timing for Tester 6, NAMESPACE STD"
time ./container 2> logstd.txt

diff logft.txt logstd.txt

make -s fclean && make -s TESTER="7" NAMESPACE="ft"
echo "Timing for Tester 7, NAMESPACE FT"
time ./container 2> logft.txt
echo "\n\n"
make -s fclean && make -s TESTER="7" NAMESPACE="std"
echo "Timing for Tester 7, NAMESPACE STD"
time ./container 2> logstd.txt

diff logft.txt logstd.txt


make -s fclean && make -s TESTER="8" NAMESPACE="ft"
echo "Timing for Tester 8, NAMESPACE FT"
time ./container 2> logft.txt
echo "\n\n"
make -s fclean && make -s TESTER="8" NAMESPACE="std"
echo "Timing for Tester 8, NAMESPACE STD"
time ./container 2> logstd.txt
diff logft.txt logstd.txt

rm logft.txt logstd.txt

make -s fclean