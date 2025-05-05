#include <bits/stdc++.h>
using namespace std;

vector<string> paginateText(string &text, int linePerPage, int charPerLine)
{
    vector<string> result;
    string word, line, page;
    int lineCount = 0, i = 0, n = text.length();

    while (i < n)
    {
        string word;
        while (i < n && text[i] != ' ')
            word += text[i++];

        if (line.empty())
        {
            line = word;
        }
        else if (line.length() + 1 + word.length() <= charPerLine)
        {
            line += " " + word;
        }
        else
        {
            // Line is full, push it to the page
            page += line + "\n";
            lineCount++;
            line = word;

            if (lineCount == linePerPage)
            {
                result.push_back(page);
                page.clear();
                lineCount = 0;
            }
        }
        i++;
    }

    // Push last line
    if (!line.empty())
    {
        page += line + "\n";
        lineCount++;
    }

    // Push last page if needed
    if (!page.empty())
    {
        result.push_back(page);
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int linePerPage, charPerLine;
    cin >> linePerPage >> charPerLine;
    cin.ignore();

    string inputText, line;
    while (getline(cin, line))
    {
        if (!inputText.empty())
            inputText += " ";
        inputText += line;
    }

    auto pages = paginateText(inputText, linePerPage, charPerLine);

    for (int i = 0; i < pages.size(); ++i)
    {
        cout << "Page " << i + 1 << ":\n";
        cout << pages[i] << "\n";
    }

    return 0;
}
