/*
Time Complexity:
      O(m × n)
      Where m is the length of string a, and n is the length of string b.

      Why?
      You fill in a 2D table of size (m+1) × (n+1), and each cell takes constant time to compute.

Space Complexity:
      O(m × n) in the current implementation using a 2D array.

      Why?
      You're storing an entire table dp[m+1][n+1] to keep track of subproblem solutions.
*/
#include <iostream>
#include <string>
using namespace std;

// Function to manually reverse a string
string Reverse(string s) {
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        char temp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = temp;
    }
    return s;
}

void lcs(string a, string b) {
    int m = b.length();
    int n = a.length();

    int dp[m + 1][n + 1];  // Dynamic programming table [m+1][n+1]

    // Fill DP table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (b[i - 1] == a[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

                cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    // Print LCS length
    cout << "Length of LCS: " << dp[m][n] << endl;

    // Trace back to build LCS string
    string result = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (b[i - 1] == a[j - 1]) {
            result += a[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    result =Reverse(result);  // Reverse manually
    cout << "LCS string: " << result << endl;
}

int main() {
    string str1 = "abcde";
    string str2 = "acdeef";

    lcs(str1, str2);

    return 0;
}

/*
 1. File and Data Comparison (Diff Tools)
       Use: Tools like diff, Git, and version control systems use LCS to compare files and highlight changes.

       Example: Finding what lines have changed in two versions of a code file.

2. Plagiarism Detection
       Use: LCS helps detect similarity between documents or code by finding common sequences.

       Example: Comparing student assignments for overlapping code.

3. Bioinformatics
       Use: Compare DNA, RNA, or protein sequences.

       Example: Identifying similar gene sequences across organisms using LCS-like algorithms.

4. Spell Checking & Correction
       Use: Matching user input with known dictionary entries.

       Example: Suggesting corrections based on longest common subsequences or edit distances.

5. Data Deduplication
       Use: Identify and remove redundant data.

       Example: Backup systems using LCS to find repeated blocks across files.

6. Natural Language Processing (NLP)
       Use: Sentence alignment, text similarity, and summarization.

       Example: Matching sentences in parallel corpora (like English–French translation data).

7. AI/ML Feature Extraction
       Use: In sequence-based models (e.g., text or speech), LCS can be a feature for similarity-based tasks.

*/