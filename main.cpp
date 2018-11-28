bool match_chars(string chars, int i, string source, int j) {
    // PRE:
    assert(chars.length() > 0 && source.length() >= chars.length());
    // POST: returns true if the whole character sequence of chars appears in
    // the given string, in the particular order. There may be different
    // characters in between.
    if(i == chars.length())
        return true;
    if(j == source.length())// && !(i < chars.length())
        return false;
    if(chars[i] == source[j])
        return(match_chars(chars, i + 1, source, j + 1));
    else
        return(match_chars(chars, i, source, j + 1));

}