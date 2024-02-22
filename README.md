# Task 1: Stack
![screen.png](https://github.com/Danchess17/mipt2024s-3-ishkhanian-d/tree/main/screen.png)
![push1.png](https://github.com/Danchess17/mipt2024s-3-ishkhanian-d/tree/main/push1.png)
![push1.png](https://github.com/Danchess17/mipt2024s-3-ishkhanian-d/tree/main/push2.png)
![pop1.png](https://github.com/Danchess17/mipt2024s-3-ishkhanian-d/tree/main/pop1.png)
![pop2.png](https://github.com/Danchess17/mipt2024s-3-ishkhanian-d/tree/main/pop2.png)
### Выводы:
1) Тест 1 показал, что конструктор стека на списке быстрее конструктора на массиве (с дефолтной capacity = 8) в 10 раз.
2) Тесты 2, 3, 4, 6, 7 показали, что функции push, pop, top (по отдельности) работают быстрее для массива, чем соответствующие для списка.
3) Тесты 2, 3, 4, 6, 7 показали, что суммарное время работы функций push, pop, top (примененные последовательно в связке друг с другом) меньше для массива, чем для списка.
4) Тест 5 показал, что вызов функций стека в рандомном хаотичном порядке в среднем по времени одинаковый для стеков, то есть, при неразумном использовании невозможно определить, кто лучше.
5) Тест 7 показал, что несмотря на пункт 1, вызов конструктора + последовательные push, pop будут работать быстрее для стека на массиве примерно в 2 раза.
6) Также были построены графики зависимости времени работы от количества вызова функции push и pop.
7) На них видим, что и для pusha, и для popa в случае стека на массиве заметны резкие скачки затрат по времени, соответствующие аллокации/деаллокации памяти соответственно.
8) На графиках видно, что стек на массиве быстрее стека на списке.
9) При компиляции c флагом -O3 push и pop соотношение скоростей массива и списка было уже не трехкратным, а семикратным. 
10) В целом, можно сказать, что стек на расширяющемся массиве работает быстрее, чем на односвязном списке.
