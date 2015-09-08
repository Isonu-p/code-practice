
//First time o(n^2) ��ʱ
/*
    void init(int * loc){
       for(int i=0;i<95;i++){
        loc[i]=-1;
       }
    }
    int numberOfLoc(int * loc){
       int length =0;
      for(int i =0;i<95;i++){
         if(loc[i]!=-1){
            length++;
         }
       }
       return length;
    }
    int lengthOfLongestSubstring(string s) {
        int Max =0;
        int location[95];
        int length;
      // memset(location,-1,sizeof(int)*26);
        init(location);
        for(int i=0;i<s.size();i++){
            if(location[s[i]-'!']==-1){
                location[s[i]-'!']=i;
            }else{
                length = numberOfLoc(location);
               Max = Max<length?length:Max;
               i=location[s[i]-'!'];
               //memset(location,sizeof(int)*26,-1);
               init(location);
            }
        }
        length = numberOfLoc(location);
       Max = Max<length?length:Max;
        return Max;
    }
    */
//72ms  i��j��ֻ����sһ�Σ�����ʱ�临�Ӷ�ΪO(N)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i = 0, j = 0; //i�Ǻ�ѡ�ַ�������㣬 j�Ǻ�ѡ�ַ������յ㡣
        int max_length = 0;
        int cur_length = 0;
        bool exist[256] = { false };
        while (j < n) {
            if (!exist[s[j]]) {
                exist[s[j]] = true;  //����������¼Ϊtrue
                j++;
            } else {
                while(s[i]!= s[j]) {
                    exist[s[i]] = false;
                    //�º�ѡ�ִ��ӵ�һ���ظ��ַ�(��s[i] == s[j]ʱ���i)�ĺ�һλ��ʼ�㣬֮ǰ��i���㣬��Ч��û�б�ɨ�赽��������Ϊfalse.
                    i++;
                }
                i++;
                j++;
            }
            cur_length = j - i;
            max_length = max_length > cur_length ? max_length : cur_length;
        }
        return max_length;
    }
};
