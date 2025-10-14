const std = @import("std");

pub fn isIsogram(str: []const u8) bool {
    var seen = std.StaticBitSet(26).initEmpty();
    for (str) |c| {
        const ch = std.ascii.toLower(c);
        if(ch >= 'a' and ch <= 'z'){
            const index = ch - @as(u8, 'a');
            if(seen.isSet(index)){
                return false;
            }
            seen.set(index);
        }
    }
    return true;
}
