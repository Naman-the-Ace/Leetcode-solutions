class Solution {
public:
    int countDaysTogether(string aa, string la,
                          string ab, string lb) {
        int days[] = {31, 28, 31, 30, 31, 30,
                      31, 31, 30, 31, 30, 31};

        auto toDays = [&](string date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));
            int total = day;

            for (int i = 0; i < month - 1; i++)
                total += days[i];

            return total;
        };

        int start = max(toDays(aa), toDays(ab));
        int end = min(toDays(la), toDays(lb));

        if (start > end) return 0;

        int count = 0;
        for (int day = start; day <= end; day++)
            count++;

        return count;
    }
};