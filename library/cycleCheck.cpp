bool cycleCheck(int u)
{
 
	vis[u] = 1;
	for(auto &v: adj[u])
	{
		if(vis[v]==0)
		{
			parent[v] = u;
			if(cycleCheck(v))return true;
		}
		else if(vis[v]==1)
		{
			if(v!=parent[u])
			{
				start = v;
				en = u;
				return true;
				break;
			}
		}
 
	}
	vis[u] = 2;
	return false;
}


