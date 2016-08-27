//����1 dp ��ʱo(n^2)
int jump(vector<int>& nums) {
	int size = nums.size();
	if (size == 0)
		return 0;
	vector<int> way(size, 0);
	for (int i = size - 2; i >=0; i--) {
		int minn = INT_MAX;
		if (i + nums[i] >= size - 1)
			way[i] = 1;
		else {
			for (int j = 1; j <= nums[i] && i + j < size; ++j) {
				minn = min(minn, way[i + j]);
			}
			if (minn != INT_MAX)
				way[i] = minn + 1;
			else
				way[i] = minn;
		}
	}
	return way[0];
}
//����2 ̰��o(n) ����������Ծλ��, ֻ��λ�����ڵ�������� , �������Ĵ���
int jump(vector<int> & nums) {
	int count = 0, cur = 0, nextMax = 0, i = 0;
	while (cur < nums.size() - 1) {
		count++;
		for (; i <= cur; ++i) {
			nextMax = max(nextMax, i + nums[i]);
		}
		cur = nextMax;
	}
	return count;
}