/**
 * @Description ���ִ������� ȥ����ߺ���ͷ� ��ƽ����
 * @Version 1.0.0
 * @Date 2024/3/29 11:49
 * @Author Kenton
 */

#include "../head/dynamic_SeqTable.h"

int main() {
    int n;
    while (std::cin >> n) {
        dynamic_SeqTable L;
        for (int i = 0; i < n; ++i) {
            ElemType score;
            std::cin >> score;
            L.ListInsert(i+1,score);
        }

        ElemType maxScore = -100000,minScore = 100000;
        ElemType sum = 0;
        for (int i = 0; i < L.length; ++i) {
            ElemType ele = L.GetElem(i+1);
            if (ele > maxScore) {
                maxScore = ele;
            }
            if (ele < minScore) {
                minScore = ele;
            }
            sum += ele;
        }

        sum -= maxScore;
        sum -= minScore;

        std::cout << "ȥ����߷ֺ���ͷֺ��ƽ����Ϊ:" << sum / (n-2);
    }

    return 0;
}
