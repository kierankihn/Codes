// C++ includes used for precompiling -*- C++ -*-

// Copyright (C) 2003-2021 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// Under Section 7 of GPL version 3, you are granted additional
// permissions described in the GCC Runtime Library Exception, version
// 3.1, as published by the Free Software Foundation.

// You should have received a copy of the GNU General Public License and
// a copy of the GCC Runtime Library Exception along with this program;
// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
// <http://www.gnu.org/licenses/>.

/** @file stdc++.h
 *  This is an implementation file for a precompiled header.
 */

// 17.4.1.2 Headers

// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cuchar>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <codecvt>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

#if __cplusplus >= 201402L
#include <shared_mutex>
#endif

#if __cplusplus >= 201703L
#include <any>
#include <charconv>
// #include <execution>
#include <filesystem>
#include <optional>
#include <memory_resource>
#include <string_view>
#include <variant>
#endif

#if __cplusplus > 201703L
#include <barrier>
#include <bit>
#include <compare>
#include <concepts>
#if __cpp_impl_coroutine
#include <coroutine>
#endif
#include <latch>
#include <numbers>
#include <ranges>
#include <span>
#include <stop_token>
#include <semaphore>
#include <source_location>
#include <syncstream>
#include <version>
#endif

namespace solution
{
    typedef long long LL;
    const int MAXN = 30 + 5;
    int n, k[MAXN];
    LL dp[MAXN][MAXN][MAXN][MAXN][MAXN];
    void init()
    {
        for (int i = n + 1; i <= 5; i++)
        {
            k[i] = 0;
        }
        for (int a = 0; a <= k[1]; a++)
        {
            for (int b = 0; b <= k[2]; b++)
            {
                for (int c = 0; c <= k[3]; c++)
                {
                    for (int d = 0; d <= k[4]; d++)
                    {
                        for (int e = 0; e <= k[5]; e++)
                        {
                            dp[a][b][c][d][e] = 0;
                        }
                    }
                }
            }
        }
        dp[0][0][0][0][0] = 1;
    }
    int main()
    {
#ifdef LOCAL
        freopen("P2483.in", "r", stdin);
        freopen("P2483.out", "w", stdout);
#endif
        while (scanf("%d", &n) != EOF && n != 0)
        {
            for (int i = 1; i <= n; i++)
            {
                scanf("%d", &k[i]);
            }
            init();
            for (int a = 0; a <= k[1]; a++)
            {
                for (int b = 0; b <= k[2]; b++)
                {
                    for (int c = 0; c <= k[3]; c++)
                    {
                        for (int d = 0; d <= k[4]; d++)
                        {
                            for (int e = 0; e <= k[5]; e++)
                            {
                                if (a < k[1])
                                {
                                    dp[a + 1][b][c][d][e] += dp[a][b][c][d][e];
                                }
                                if (b < k[2] && b < a)
                                {
                                    dp[a][b + 1][c][d][e] += dp[a][b][c][d][e];
                                }
                                if (c < k[3] && c < b)
                                {
                                    dp[a][b][c + 1][d][e] += dp[a][b][c][d][e];
                                }
                                if (d < k[4] && d < c)
                                {
                                    dp[a][b][c][d + 1][e] += dp[a][b][c][d][e];
                                }
                                if (e < k[5] && e < d)
                                {
                                    dp[a][b][c][d][e + 1] += dp[a][b][c][d][e];
                                }
                            }
                        }
                    }
                }
            }
            std::printf("%lld\n", dp[k[1]][k[2]][k[3]][k[4]][k[5]]);
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}