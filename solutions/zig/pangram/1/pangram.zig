const std = @import("std");
pub fn isPangram(str: []const u8) bool {
    var bitset = std.StaticBitSet(26).initEmpty();
    for(str) |ch| {
        const lower_ch = std.ascii.toLower(ch);
        if(lower_ch >= 'a' and lower_ch <= 'z'){
            const index = lower_ch - @as(u8, 'a');
            bitset.set(index);
        }
    }
    if(bitset.count() != 26) return false;
    return true;
}