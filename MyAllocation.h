/// @file

#ifndef MY_ALLOCATION
#define MY_ALLOCATION

/// @brief Функция выделения блока памяти
/// @param n_elems Новое количество элементов для выделения
/// @param size_elems Размер элементов для выделения
/// @param poison Указатель на ядовитое значение, которым заполнятся выделенные ячейки
/// @return Указатель на выделенный блок памяти

void* MyCalloc (size_t n_elems, size_t size_elems, const void* poison);

/// @brief Функция изменения размера уже выделенного блока памяти
/// @param[in] memory Указатель на выделенный блок памяти
/// @param[in] n_elements Новое количество элементов для выделения
/// @param[in] size_elements Размер элементов для выделения
/// @param[in] previous_n_elements Количество элементов в блоке до вызова функции
/// @param[in] poison Указатель на ядовитое значение, которым заполнятся добавленные ячейки
/// @return Указатель на перевыделенный блок памяти

void* MyRecalloc (void* memory, size_t n_elements, size_t size_elements, size_t previous_n_elements, const void* poison);

#endif // MY_ALLOCATION