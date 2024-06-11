/*
1.1. [# 25] Квадратичная задача о назначениях. Есть множество предприятий, которые могут быть расположены в 𝑛 местах. 
Для каждой пары мест задано расстояние и для каждой пары производств задано количество материала, перевозимого между двумя производствами.
Требуется расставить производства по местам (два производства нельзя размещать в одном месте) таким образом,
что сумма расстояний, умноженных на соответствующие потоки, будет минимальной.
Сдача работы без тестов – коэффициент 0.5.
Выполнить работу.
*/

#include "task.h"
#include "Qap.h"

void ShowResult(int rMin, std::vector<int> queue)
{
    std::cout << "R = " << rMin << "; vector: ";
    copy(queue.begin(), queue.end(), std::ostream_iterator<size_t>(std::cout, " "));
    std::cout << "\n\n";
}

int main()
{
    boost::timer::auto_cpu_timer t;

    std::vector<std::vector<int>> C = {
        { 0, 17, 30, 5, 3 },
        { 0, 0, 25, 21, 21 },
        { 0, 0, 0, 3, 4 },
        { 0, 0, 0, 0, 13 },
        { 0, 0, 0, 0, 0 },
    };

    std::vector<std::vector<int>> Q = {
        { 0, 8, 11, 8, 1},
        { 0, 0, 4, 13, 1 },
        { 5, 2, 0, 12, 14 },
        { 7, 12, 8, 0, 13 },
        { 2, 12, 11, 10, 0 },
    };

    Qap qap = Qap(C, Q);
    //qap.setDebugModeOutput(true);

    qap.showMatrixC();
    qap.showMatrixQ();

    qap.Run();

    ShowResult(qap.GetRMin(), qap.GetQueueMin());

    return 0;
}
