#include "underfile.h"

void test_to_remoove() {
    int i = 0;
    leksem *head = create(i);
    for (i = 1; i < 96; i++) {
        add_element_n_position(i * 5, i, head);
    }
    for (int i = 10; i < 94; i++) {
        remove_element(i, head);
    }
    print_list(head);
}

void print_list(leksem *head) {
    leksem *p = head;
    while (p) {
        printf("\n%c", p->value);
        p = p->next;
    }
}
// выводит список в обратном порядке
void printer(leksem *head) {
    leksem *p = head;
    leksem *new_list = NULL;
    while (p) {
        if (p->type == number) {
            new_list = push_double(p->value_double, new_list);
            p = p->next;
        } else {
            new_list = push(p->value, new_list);
            p = p->next;
        }
//        priority_setter(&new_list);
    }

    printf("\n");
    while (new_list) {
        if (new_list->type == number) {
            printf("%.lf ", new_list->value_double);
            new_list = new_list->next;
        } else {
            printf("%c ", new_list->value);
            new_list = new_list->next;
        }
    }
}
// 6 2 * 8 + 8 2 * + 2 2 4 6 * 2 * 4 8 + - * + 10 * +
// 6 2 * 8 + 8 2 * + 2 2 4 6 * 2 * 4 8 + - * + 10 * + 
// 611 233 * 8 + 800 2 * + 2 2 4 6 * 245 * 4 8231 + - * + 1033 * +
// 611 233 * 8 + 800 2 * + 2 2 4 6 * 245 * 4 8231 + - * + 1033 * + 
// то есть тут в функции мы выделяем память под структуру и получаем указатель
// на выделенную память
//  после чего записываем в поле значение нужное нам значение и в поле для
//  указателя на слудующий жлемент списка кладем NULL
// после чего возвращаем казательна выделенную память
// просто работа с динамической памятью и куча и никакой магии

/**
 * @brief создает узел
 * @return возвращает указатель на созданный
 */
leksem *create(int data) {
    leksem *tmp = malloc(sizeof(leksem));
    tmp->value = data;
    tmp->next = NULL;
    return (tmp);
}

// Голова списка - первый элемент списка; Хвост списка - все последующие
// элементы, являющиеся, в свою очередь списком
leksem *push(int data, leksem *head) {
    // Выделение памяти под узел списка
    leksem *tmp = (leksem *)malloc(sizeof(leksem));
    // Присваивание значения узлу
    tmp->value = data;
    // Присваивание указателю на следующий элемент значения указателя на
    // «голову» первоначального списка
    tmp->next = head;
    return (tmp);
}
// приходит только голова
leksem *add_element_to_end(int data, leksem *head) {
    // Выделение памяти под узел списка
    leksem *tmp = (leksem *)malloc(sizeof(leksem));
    // Присваивание значения узлу
    tmp->value = data;
    // Присваивание указателю на следующий элемент значения указателя на
    // «голову» первоначального списка
    tmp->next = NULL;
    // тупо перебираем все указатели ну заебок
    leksem *p = head;
    while (p != NULL) p = p->next;
    // обратить внимание что цикл while в одну строку
    p = tmp;
    return (tmp);
}

leksem *remove_element(int data, leksem *head) {
    // Присваивание новому указателю  tmp указателя head, p - NULL
    leksem *tmp = head, *p = NULL;
    // Проверка списка на пустоту
    if (head == NULL) return NULL;
    // Если список не пуст, поиск указателя на искомый элемент
    while (tmp && tmp->value != data) {
        p = tmp;
        tmp = tmp->next;
    }
    // Если удаляемый элемент первый
    if (tmp == head) {
        free(head);
        return tmp->next;
    }
    // Если в списке нет искомого элемента, то возвращаем первоначальный список
    if (!tmp) return head;
    // Присваивание новому указателю указателя tmp
    p->next = tmp->next;
    // Освобождение памяти для указателя tmp
    free(tmp);
    return head;
}

/**
 * @brief // добавиляет элемент в любую позицию
 * нужно посылать минимум второй элемент
 */
leksem *add_element_n_position(int data, int n, leksem *head) {
    leksem *p = head;
    int count = 1;
    while (count < n - 1 && p != NULL) {
        p = p->next;
        count++;
    }
    leksem *tmp = malloc(sizeof(leksem));
    tmp->value = data;
    // данная штука работает для 2 элементов которые есть в списке
    tmp->next = p->next;
    p->next = tmp;
    return (tmp);
}

// просто чистим с первого элемента до последнего
leksem *remove_all(leksem *head) {
    while (head != NULL) {
        leksem *tmp = head;
        head = head->next;
        free(tmp);
    }
    return NULL;
}

int pop(leksem **head) {
    int value = 0;
    if (head == NULL) {
        printf("\n error");
    } else {
        leksem *tmp = *head;
        value = tmp->value;

        *head = tmp->next;
        free(tmp);
    }

    return value;
}
int view_pop(leksem **head) {
    int type = 0;
    if (head == NULL) {
        printf("\n error");
    } else {
        leksem *tmp = *head;
        type = tmp->type;
    }

    return type;
}
int notempty(leksem *head) { return head != NULL; }