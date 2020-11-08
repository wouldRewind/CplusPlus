#include <iostream>
using namespace std;
// функция, проверяющая, является ли место свободным
bool isFree(int* places, int N, int place)
{
    for (int i = 0; i < N; i++)
        if (places[i] == place) 
            return true;
    return false; // дефолтный случай - место не свободно
}

int main() {
    setlocale(LC_ALL, "rus");
    int wagon = 9;
    int max = 54;
    cout << "Введите количество свободных мест, а затем номера этих мест(в вагоне всего 54 места): " << endl;
    int N;
    cin >> N;

    int* places = new int[N];
    // заполнение
    for (int i = 0; i < N; i++)
        cin >> places[i];
    // алгоритм
    int maxAmount = 0; // максимальное количество подряд идущих вагонов
    int amount = 0; // текущее количество подряд идущих вагонов
    // так как в основном цикле есть два вложенных дополнительных цикла, проверяющих свободность мест слева и справа, прдется ввести флаг, который позволил бы второму циклу не делать лишнюю работу, если слева хоть одно место занято
    for (int i = 1; i <= wagon; i++)
    {
        bool free = true;
        int left = 4 * i;
        int right = max - 2 * (i - 1);
        // чекаем левую часть
        for (int j = left; j > left - 4; j--)
        {
            if (!isFree(places, N, j))
            {
                // если место занято, нет смысла искать дальше
                free = false;
                break;
            }
        }
        // чекаем правую часть
        for (int j = right; j > right - 2; j--)
        {
            if (!free || !isFree(places, N, j))
            {
                free = false; // левая часть могла быть свободной, а вот в правой нашлось-таки несвободное местечко
                break; // нет смысла искать дальше
            }
        }
        // если переменная free == true, то вагон оказался свободным и его можно "плюсануть". Если нет - вагон не пуст, и надо сравнить текущее количество подряд идущих вагонов с максимальным
        if (!free)
        {
            if (amount > maxAmount) maxAmount = amount;
            amount = 0;
        }
        else {
            // костыль: последний вагон не считается, поэтому приходится считать его отдельно 
            amount++;
            if (i == wagon) {
                if (amount > maxAmount) maxAmount = amount;
            }
        } 
    }
    if (maxAmount == 0) cout << "К сожалению, свободных купе нет вовсе :(";
    else cout << "Максимальное число подряд идущих купе = " << maxAmount << endl;




}