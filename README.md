# Task 1: Stack
### Выводы:
1) Тест 1 показал, что конструктор стека на списке быстрее конструктора на массиве.
2) Тесты 2, 3, 4, 6, 7 показали, что функции push, pop, top (по отдельности) работают быстрее для массива, чем соответствующие для списка.
3) Тесты 2, 3, 4, 6, 7 показали, что суммарное время работы функций push, pop, top (примененные последовательно в связке друг с другом) меньше для массива, чем для списка.
4) Тест 5 показал, что вызов функций стека в рандомном хаотичном порядке в среднем по времени одинаковый для стеков, то есть, при неразумном использовании невозможно определить, кто лучше.
5) Тест 7 показал, что несмотря на пункт 1, вызов конструктора + последовательные push, pop будут работать быстрее для стека на массиве.
6) В целом, можно сказать, что стек на расширяющемся массиве работает быстрее, чем на односвязном списке.
