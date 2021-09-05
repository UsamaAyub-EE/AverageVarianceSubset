#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
double var(vector <int> s)
{
	double sum=0,mean;
	for(auto i=0;i<s.size();++i)
	{
		sum+=s[i];
	}
	mean=sum/s.size();
	double sum_y_i=0;
	for(auto i=0;i<s.size();++i)
	{
		sum_y_i+=pow((s[i]-mean),2);
	}
	return (sum_y_i/s.size());
}
class AverageVarianceSubset{
	public:
		double average(vector <int> s, int R)
		{
			double var_sum=0;
			size_t count=pow(2,s.size());
			size_t cnt=0;
			sort(s.begin(),s.end());
			vector<int> temp;
			for(auto i=1;i<count;++i)
			{
				temp.clear();
				for(auto j=0;j<s.size();++j)
				{
					if((i&(1<<j))>0)
					{
						temp.push_back(s[j]);
					}
				}
				if((temp[temp.size()-1]-temp[0])<=R)
				{
					++cnt;
					var_sum+=var(temp);
					temp.clear();
				}
			}

			return (var_sum/cnt);
		}
};