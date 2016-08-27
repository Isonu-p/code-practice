class Solution {
public:
/*
�����������Ҫ���ǣ�

1. �������substring��ȵĻ�����Ϊtrue

2. �������substring�м�ĳһ���㣬��ߵ�substringsΪscramble string��
ͬʱ�ұߵ�substringsҲΪscramble string����Ϊtrue

3. �������substring�м�ĳһ���㣬s1��ߵ�substring��s2�ұߵ�substringΪscramble
string, ͬʱs1�ұ�substring��s2��ߵ�substringҲΪscramble
string����Ϊtrue

*/
bool dp[100][100][101];
bool init_dp(string s1, string s2) {
	memset(dp, 0, sizeof(dp));
	int len = s1.size();
	for (int k = 1; k <= len; k++) {
		for (int i = 0; i <= len - k; i++) {
			for (int j = 0; j <= len - k; j++) {
				if (s1.substr(i, k) == s2.substr(j, k)) {
					dp[i][j][k] = true;
				}
				else {
					for (int l = 1; l < k; l++) {
						if ((dp[i][j][l] && dp[i + l][j + l][k - l]) || (dp[i][j + k - l][l] && dp[i + l][j][k - l])) {
							dp[i][j][k] = true;
							break;
						}
					}
				}
			}
		}
	}
	return dp[0][0][len];
}
bool isScramble(string s1, string s2) {
	return init_dp(s1, s2);
}

};