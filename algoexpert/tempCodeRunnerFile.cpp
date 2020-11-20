    int s_len = s.length();
    for (int i = 0; i < (s_len / 2); i++)
    {
        if (s[i] != s[s_len - i - 1])
        {
            return false;
        }
    }
    return true;