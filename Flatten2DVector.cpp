class Vector2D {
    private:
        vector<vector<int>>::iterator currStart;
        vector<vector<int>>::iterator currEnd;
        vector<int>::iterator start;
        vector<int>::iterator end;

    public:
        Vector2D(vector<vector<int>>& vec2d) {
            currStart = vec2d.begin();
            currEnd = vec2d.end();
            start = end;
        }

        int next() {
            int result = *start;
            ++start;

            return result;
        }

        bool hasNext() {
            while(currStart != currEnd && start == end) {
                start = (*currStart).begin();
                end = (*currStart).end();
                ++currStart;
            }

            return start != end;
        }
   };