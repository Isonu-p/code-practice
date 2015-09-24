
class Solution(object):
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int

        n!=2x*3y*5z*...
        ��Ȼ0�ĸ�������min(x,z)������min(x,z)==z
        [n/k]����1~n���ܱ�k�����ĸ���
        [n/2] > [n/5]
        [n/2^2] > [n/5^2]
        ����
        [n/2^p] > [n/5^p]
        """
        ret = 0
        while n:
            ret += int(n/5)
            n = int(n/5)
        return ret
