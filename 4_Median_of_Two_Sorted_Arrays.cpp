class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int i = 0; 
        int j = 0; 
        int tamanho1 = nums1.size(); 
        int tamanho2 = nums2.size(); 
        int tamanho = tamanho1 + tamanho2; 
        int nums[tamanho];
        int k = 0; 
        double mediana; 

        // mescla os vetores
        while (i < tamanho1 && j < tamanho2){
            if (nums1[i] < nums2[j]){
                nums[k] = nums1[i];
                i++;
            }
            else{
                nums[k] = nums2[j];
                j++;
            }
            k++;
        }

        // adiciona os elementos restantes
        if (i < tamanho1){
            while (i < tamanho1){
                nums[k] = nums1[i];
                i++;
                k++;
            }
        }
        else{
            while (j < tamanho2){
                nums[k] = nums2[j];
                j++;
                k++;
            }
        }

        // calcula a mediana
        if (tamanho % 2 != 0){         
            mediana = nums[((tamanho+1)/2)-1] / 1.0;
        }
        else{
            mediana = (nums[((tamanho)/2)-1] + nums[(tamanho/2)])/2.0;
        }
        return mediana;
    }
};