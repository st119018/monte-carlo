# monte-carlo

### To build
- mkdir build
- cd build
- cmake . .\
- cmake --build .
- .\monte-carlo
---------------
Программа считает число пи методом Монте-Карло и измеряет время работы. Пример:
>elina@Ubuntu:~/proj/monte-carlo/build$ ./monte-carlo
>
>Enter number of threads: 100
>
>Calculated pi: 3.13784
>
>Time spent: 7002 us using 100 threads

>elina@Ubuntu:~/proj/monte-carlo/build$ ./monte-carlo
>
>Enter number of threads: 50
>
>Calculated pi: 3.14196
>
>Time spent: 7691 us using 50 threads

>elina@Ubuntu:~/proj/monte-carlo/build$ ./monte-carlo
>
>Enter number of threads: 20
>
>Calculated pi: 3.14756
>
>Time spent: 11979 us using 20 threads

>elina@Ubuntu:~/proj/monte-carlo/build$ ./monte-carlo
>
>Enter number of threads: 5
>
>Calculated pi: 3.13972
>
>Time spent: 13546 us using 5 threads

Многократно запустив подсчет с количеством точек, равным 100 000, я убедилась, что данная в задании оценка верна