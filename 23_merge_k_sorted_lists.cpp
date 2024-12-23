/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // funcao principal
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        return mesclarKListasAuxiliar(lists, 0, lists.size()-1);
    }

    // funcao auxiliar
    ListNode* mesclarKListasAuxiliar(vector<ListNode*>& listas, int inicio, int fim) {
        if(inicio > fim) return NULL; 
        if(inicio == fim) return listas[inicio];

        int meio = inicio + (fim - inicio)/2;
        ListNode* esquerda = mesclarKListasAuxiliar(listas, inicio, meio);
        ListNode* direita = mesclarKListasAuxiliar(listas, meio + 1, fim);
        return mesclar(esquerda, direita);
    }

    // merge
    ListNode* mesclar(ListNode* cabecaLista1, ListNode* cabecaLista2) {
        ListNode* cabeca = new ListNode(-1);
        ListNode* cabecacauda = cabeca;

        while(cabecaLista1 != NULL && cabecaLista2 != NULL){
            if(cabecaLista1->val < cabecaLista2->val){
                cabecacauda->next = cabecaLista1;
                cabecaLista1 = cabecaLista1->next;
            }else{
                cabecacauda->next = cabecaLista2;
                cabecaLista2 = cabecaLista2->next;
            }
            cabecacauda = cabecacauda->next;
        }
        cabecacauda->next = (cabecaLista1 != NULL) ? cabecaLista1 : cabecaLista2;
        return cabeca->next;
    }
};
