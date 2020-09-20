
bool isAnagram(char * s, char * t){
    int a = strlen(s);
    int b = strlen(t);
    if (a != b) {
        return false;
    }
    int c[26] = {0};
    for (int i = 0; i < (a<b?b:a); i++){
        c[s[i] - 'a']++;
        c[t[i] - 'a']--;
    }
    for (int j = 0; j < 26;j++){
        if(c[j] != 0){
            return false;
        }
    }
        return true;
   
    
}