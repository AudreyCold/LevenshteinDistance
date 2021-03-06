# LevenshteinDistance

В ходе выполнения данной работы, были задействованы класс Stack (для внесения и сохранения порядка преобразований – «редакционного предписания») и класс 	LevenshteinDistance для нахождения и хранения значения расстояния Левенштейна и редакционного предписания для введённой пары символов.
Для нахождения редакционного расстояния был создан двухмерный динамический массив matrix_distance, в ячейках которого хранятся числа, являющиеся редакционным расстоянием между префиксами двух введённых строк.
Для нахождения редакционного предписания был создан двухмерный динамический массив matrix_prescription, такого же размера, что и matrix_distance, но хранящий в себе буквы, которые обозначают проведённую операцию (D (англ. delete) — удалить, I (англ. insert) — вставить, R (replace) — заменить, M (match) — совпадение).

Подробнее о том, что такое расстояние Левенштейна, можно прочесть. перейдя по следующей ссылке: https://en.wikipedia.org/wiki/Levenshtein_distance

Для нахождения расстояния Левенштейна мы создаём массив matrix_distance, описание которого приводится выше. Вначале мы заполняем его левый столбец таким образом, что все элементы, начиная от того, что с индексом 1, и заканчивая тем, что с индексом размера наибольшей строки, равняются индексу, присущему текущему элементу. Значение каждого элемента – это цена вставки, чтобы из пустой строки получить текущий префикс. 
Далее мы проводим те же действия, но уже для верхней строки, для которой значения элементов есть цена удаления. 
После этого мы заполняем остальные элементы в массиве. Причём значение для каждого элемента определяется минимальным значением среди тех, что были перед ним:  элементы сверху, слева и по диагонали слева. После этого мы прибавляем единицу, если символы являются разными, иначе не прибавляем ничего. 
Расстоянием Левенштейна будет значение того элемента, что находится в правом нижнем углу.
Для нахождения редакционного предписания, мы подобным образом создаём массив matrix_prescription, так же заполняем левый столбец и верхнюю строку, но уже буквами «I» и «D» соответственно. И, основываясь на принципе заполнения matrix_distance, соответсвенно выбору шага пишем подходящую букву. При нахождении непосредственно порядка действий, мы отталкиваемся от нижнего правого угла. Заносим его значение в стек, двигаемся влево, в зависимости от того, какая буква стояла в элементе. Повторяем данные операции, пока не достигнем края – левого или верхнего.
Поскольку мы заносим значения в стек, а не в очередь, значение самого первого занесённого элемента окажется в конце, что нам и нужно, с учётом того, что мы двигаемся от последнего элемента к первым.

