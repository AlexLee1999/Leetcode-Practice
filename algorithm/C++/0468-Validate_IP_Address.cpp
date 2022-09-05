class Solution {
public:
    string validIPAddress(string queryIP) {
        if (IPv4(queryIP)) {
            return "IPv4";
        }
        if (IPv6(queryIP)) {
            return "IPv6";
        }
        return "Neither";
    }
    bool IPv4(string ip) {
        vector<string> ans;
        int prev = 0;
        for (int i=0; i<ip.size(); ++i) {
            if (ip[i] == '.') {
                string tmp = ip.substr(prev, i - prev);
                if (!validsubIPv4(tmp)) {
                    return false;
                }
                ans.push_back(ip.substr(prev, i - prev));
                prev = i + 1;
            } else if ('0' <= ip[i] && ip[i] <= '9') {
                continue;
            } else {
                return false;
            }
        }
        string tmp = ip.substr(prev, ip.size() - prev);
        if (!validsubIPv4(tmp)) {
            return false;
        }
        ans.push_back(tmp);
        if (ans.size() != 4) {
            return false;
        }
        return true;
    }
    bool IPv6(string ip) {
        vector<string> ans;
        int prev = 0;
        for (int i=0; i<ip.size(); ++i) {
            if (ip[i] == ':') {
                string tmp = ip.substr(prev, i - prev);
                if (!validsubIPv6(tmp)) {
                    return false;
                }
                ans.push_back(tmp);
                prev = i + 1;
            } else if ('0' <= ip[i] && ip[i] <= '9') {
                continue;
            } else if ('A' <= ip[i] && ip[i] <= 'F') {
                continue;
            } else if ('a' <= ip[i] && ip[i] <= 'f') {
                continue;
            } else {
                return false;
            }
        }
        string tmp = ip.substr(prev, ip.size() - prev);
        if (!validsubIPv6(tmp)) {
            return false;
        }
        ans.push_back(tmp);
        if (ans.size() != 8) {
            return false;
        }
        return true;
    }
    bool validsubIPv4(string sub_ip) {
        if (sub_ip == "") {
            return false;
        }
        if (sub_ip.size() > 3) {
            return false;
        }
        if (sub_ip[0] == '0' & sub_ip != "0") {
            return false;
        }
        if (stoi(sub_ip) >= 256) {
            return false;
        }
        return true;
    }
    bool validsubIPv6(string sub_ip) {
        if (sub_ip.size() > 4 || sub_ip.size() <= 0) {
            return false;
        }
        return true;
    }
};
// Time : O(n)
// Space : O(n)