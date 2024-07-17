class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        int n = path.length();
        string dir;

        for (int i = 0; i < n; ++i) {
            while (i < n && path[i] == '/') {
                ++i;
            }

            while (i < n && path[i] != '/') {
                dir += path[i];
                ++i;
            }

            if (dir == "..") {
                if (!s.empty()) {
                    s.pop();
                }
            } else if (dir != "." && !dir.empty()) {
                s.push(dir);
            }

            dir.clear();
        }

        string simplifiedPath;
        while (!s.empty()) {
            simplifiedPath = '/' + s.top() + simplifiedPath;
            s.pop();
        }

        if (simplifiedPath.empty()) {
            simplifiedPath = "/";
        }

        return simplifiedPath;
    }
};
