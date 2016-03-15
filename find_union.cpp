int parent[MAX], rnk[MAX];

void make_set(int n)
{
    for(int i = 0; i < n; i++)
    {
        rnk[i] = 0;
        parent[i] = i;
    }
}
int find(int i)
{
    if(parent[i] != i)
        parent[i] = find(parent[i]);
    return parent[i];
}
void Union(int x, int y)
{
    int xroot = find(x);
    int yroot = find(y);

    if(rnk[xroot] < rnk[yroot])
        parent[xroot] = yroot;
    else if(rnk[xroot] > rnk[yroot])
        parent[yroot] = xroot;
    else
    {
        parent[xroot] = yroot;
        rnk[yroot]++;
    }
}
