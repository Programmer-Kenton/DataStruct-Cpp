/**
 * @Description KMP�㷨
 * @Version 1.0.0
 * @Date 2024/4/12 22:13
 * @Author Kenton
 */

#include <iostream>
#include <string>
#include <vector>

// ��������ƥ���
std::vector<int> buildNext(const std::string &pattern) {
    // ��ȡ�ַ�������
    int n = pattern.size();
    // next��������Ԫ��ֵ����Ϊ0
    std::vector<int> next(n, 0);

    // ���ٵ�ǰ��ƥ������׺����
    int j = 0;
    printf("next[%d] = %d\n",j,next[0]);

    // �ӵڶ����ַ���ʼ�����ַ���
    for (int i = 1; i < n; ++i) {
        // ��j>0�ҵ�ǰ�ַ�pattern[i]��pattern[j]��ƥ��ʱ
        while (j > 0 && pattern[i] != pattern[j]) {
            // ��j���˵�next[j-1]��Ӧ����֪���ǰ��׺����
            j = next[j - 1];
        }
        // ����ǰ�ַ�pattern[i]��pattern[j]ƥ��
        if (pattern[i] == pattern[j]) {
            // ����j����ʾ��ƥ�䳤�ȼ�1
            ++j;
        }
        // ����next[i]Ϊ��ǰ��jֵ������ǰ�ַ�֮ǰ���Ӵ��У�����ǰ��׺�ĳ���
        next[i] = j;
        printf("next[%d] = %d\n",i,next[i]);
    }

    return next;
}

// KMP�����㷨
std::vector<int> kmpSearch(const std::string &text, const std::string &pattern) {
    // �洢ƥ��λ��
    std::vector<int> matches;

    // ����pattern��next����
    std::vector<int> next = buildNext(pattern);

    // �������m���ı����ȣ���n��ģʽ���ȣ�
    int m = text.size(), n = pattern.size();

    // i���ı�ָ�룩��j��ģʽָ�룩����ʼֵ��Ϊ0��
    int i = 0, j = 0;

    // ģʽ��ƥ�����/����ƥ�����û���ҵ�������ѭ��
    while (i < m && j < n) {
        if (text[i] == pattern[j]) {
            // ��text[i]��pattern[j]���ʱ��ͬʱ����i��j
            ++i;
            ++j;
        } else if (j > 0) {
            // ��j > 0���ַ���ƥ�䣬������next�������j����֪��ǰ׺λ��
            j = next[j - 1];
        } else {
            // jΪ0 ����һ���ַ���ƥ�� �ı���ָ����� ģʽ��ָ�벻��
            ++i;
        }

        // ��һ��if�жϽ�����jָ����� ��ƥ��ɹ��򳬹�ģʽ����Χ j == n
        if (j == n) {
            //��¼ƥ��ɹ�����ʼλ��
            matches.push_back(i - j);
            //���˵�ǰһ������ǰ��׺�Ľ���λ�ã�����Ѱ����һ��ƥ��
            j = next[j - 1];
        }
    }

    return matches;
}

int main() {
    std::string text = "ababcabcaabcac";
    std::string pattern = "ababcaa";

    std::vector<int> match_positions = kmpSearch(text, pattern);

    if (!match_positions.empty()) {
        std::cout << "Pattern \"" << pattern << "\" found at positions: ";
        for (int pos : match_positions) {
            std::cout << pos << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Pattern \"" << pattern << "\" not found in the given text." << std::endl;
    }

    return 0;
}

