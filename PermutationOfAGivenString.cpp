void Iamforhelp(string s, int i, set<string> &ans)
{

    if (s[i] == '\0')
    {

        ans.insert(s);
        return;
    }

    for (int j = i; s[j] != '\0'; j++)
    {
        swap(s[i], s[j]);
        Iamforhelp(s, i + 1, ans);
        swap(s[i], s[j]);
    }
}

vector<string> find_permutation(string S)
{

    set<string> ans;

    Iamforhelp(S, 0, ans);

    vector<string> a(ans.begin(), ans.end());
    return a;
}