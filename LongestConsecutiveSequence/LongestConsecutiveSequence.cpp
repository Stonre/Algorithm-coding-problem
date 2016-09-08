#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int longestConsecutive(vector<int>& nums) {
	int len = nums.size();
	if (len<=0)
		return 0;
	sort(nums.begin(),nums.end());
	int lenm = 1;
	int lent = 1;

	for (int i=1;i<len;i++){
		if (nums[i]-nums[i-1]==1){
			lent++;
			if (lent>lenm)
			{
				lenm = lent;
				lent = 1;
			}
		}
		else{
			lent = 1;
		}
	}
	return lenm;
}

int main(){

}