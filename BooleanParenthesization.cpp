/* Given an expression, s, with operands and operators (OR , AND , XOR), in how many ways can you evaluate the expression to true, by grouping in different ways?
Operands are only true and false. */

// MAKE SURE WE CLEAR THE UNORDERED MAP BEFORE USE!
// Function basically returns the number of ways!

unordered_map<string,int>mp;

int boolean_p(string s,int i, int j, bool isTrue)
{
	if(i > j) return 0;
	if(i == j)
	{
		if(isTrue == true)
			if(s[i] == 'T') return true;
			else return false;
		else
			if(s[i] == 'F') return true;
			else return false;
	}
	string temp = to_string(i);
	temp.push_back(' '); 
	temp.append(to_string(j)); 
	temp.push_back(' ');
	temp.append(to_string(isTrue));
	
	if(mp.find(temp) != mp.end())
		return mp[temp];
	
	int ans = 0;
	for(int k = i+1; k <= j-1; k += 2)
	{
		int lf = boolean_p(s,i,k-1,false);
		int lt = boolean_p(s,i,k-1,true);
		int rf = boolean_p(s,k+1,j,false);
		int rt = boolean_p(s,k+1,j,true);
		
		if(s[k] == '&')
		{
			if(isTrue == true)
			{
				ans += lt * rt;
			}
			else
			{
				ans += lf * rf + lt*rf + lf*rt;
			}
		}
		else if(s[k] == '|')
		{
			if(isTrue == true)
			{
				ans += lt * rt + lt*rf + lf*rt;
			}
			else
			{
				ans += lf * rf;
			}
		}
		else if(s[k] == '^')
		{
			if(isTrue == true)
			{
				ans += lf*rt + lt*rf;
			}
			else
			{
				ans += lt*rt + lf*rf;
			}
		}
	}
	mp[temp] = ans;
	return ans;
}
