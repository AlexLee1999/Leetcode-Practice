/**
 * // This is the FontInfo's API interface.
 * // You should not implement it, or speculate about its implementation
 * class FontInfo {
 *   public:
 *     // Return the width of char ch when fontSize is used.
 *     int getWidth(int fontSize, char ch);
 *     
 *     // Return Height of any char when fontSize is used.
 *     int getHeight(int fontSize)
 * };
 */
class Solution {
public:
    int maxFont(string text, int w, int h, vector<int>& fonts, FontInfo fontInfo) {
        int left = 0;
        int right = fonts.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canFit(text, w, h, fonts[mid], fontInfo)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right == -1 ? -1 : fonts[right];
    }
    bool canFit(string& text, int w, int h, int font, FontInfo& fontInfo) {
        if (fontInfo.getHeight(font) > h) {
            return false;
        }
        int width = 0;
        for (int i=0; i<text.size(); ++i) {
            width += fontInfo.getWidth(font, text[i]);
            if (width > w) {
                return false;
            }
        }
        return true;
    }
};
// Time : O(nlogn)
// Space : O(1)