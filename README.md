### sortfast -- a laboratory to explore sorting performance

<https://cantrip.org/sortfast.html>

Examples:
```
make all
make CC=g++-9 INDEXED
make CC=clang++-9 ANDANDOR
make CC=clang++-9 INDEXED_PESSIMAL_ON_GCC
make CC=g++-9 CHECK=CHECK BOG
```

Same input, same algorithm, varying performance:

 <table>
   <thead>
     <tr> <th> Variant </th>
       <th> Compiler </th>
       <th> Haswell </th>
       <th> SkylakeX </th>
       <th> Zen2 <br> -march=znver2 </th>
       <th> * </th>
     </tr>
   </thead>
   <tbody>
     <tr><td rowspan=2> STD  </td><td> G++ </td><td> 1 (10.2s) </td><td> 1 (7.3s) </td><td> 1 (9.0s) </td><td></td></tr>
     <tr><td>                        Clang </td><td> 1 (10.0s) </td><td> 1 (7.3s) </td><td> 1 (8.5s) </td><td></td></tr>
     <tr><td rowspan=2> BOG  </td><td> G++ </td><td> 1.1 (11.5s) </td><td> 1.1  (8.2s) </td><td> 1.1 (10.3s) </td><td></td></tr>
     <tr><td>                        Clang </td><td> 1.1 (11.3s) </td><td> 1.1  (7.9s) </td><td> 1.1 (9.4s) </td><td></td></tr>
     <tr><td rowspan=2> &&|  </td><td> G++ </td><td> .56  (5.7s) </td><td>  .61 (4.5s) </td><td> .82 (7.4s) </td><td></td></tr>
     <tr><td>                        Clang </td><td> <b>.49</b> (4.9s) </td><td> <b> .47</b> (3.4s) </td><td> .75 (6.4) </td><td>!</td>/tr>
     <tr><td rowspan=2> IX   </td><td> G++ </td><td>  .79 (8.1s) </td><td>  .89 (6.5s) </td><td> .94 (8.5s) </td><td></td></tr>
     <tr><td>                        Clang </td><td>  .66 (6.6s) </td><td>  .63 (4.6s) </td><td> .87 (7.4s) </td><td></td></tr>
     <tr><td rowspan=2> IX-P </td><td> G++ </td><td> 1.2 (12.0s) </td><td>  1.2 (8.4s) </td><td> <i>2.7</i> (24s) </td><td></td>!</tr>
     <tr><td>                        Clang </td><td>  .64 (6.4s) </td><td>  .60 (4.4s) </td><td> .77 (7.4s) </td><td></td></tr>
     <tr><td rowspan=2> ROT  </td><td> G++ </td><td> .72  (7.3s) </td><td>  .70 (5.1s) </td><td> .73 (6.6s) </td><td></td></tr>
     <tr><td>                        Clang </td><td>  .68 (6.8s) </td><td>  .66 (4.8s) </td><td> 1.2 (9.9s) </td><td></td></tr>
     <tr><td rowspan=2> CMOV </td><td> G++ </td><td> 1.1 (11.3s) </td><td>  1.1 (8.0s) </td><td> .82 (7.4s) </td><td></td></tr>
     <tr><td>                        Clang </td><td> <b>.49</b> (4.9s)</td><td><b>.47</b> (3.4s) </td><td> .74 (6.3s) </td><td>!</td></tr>
     <tr><td rowspan=2> IX1  </td><td> G++ </td><td> <i>1.6</i> (15.9s) </td><td> <i>1.6</i> (11.8s) </td><td> .82 (7.4) </td><td>!</td></tr>
     <tr><td>                        Clang </td><td>  .61 (6.1s) </td><td>  .62 (4.5s) </td><td> .73 (6.6s) </td><td></td></tr>
     <tr><td rowspan=2> IX2  </td><td> G++ </td><td> 1.1 (11.2s) </td><td>  1.1 (8.2s) </td><td> <i>2.1</i> (19s) </td><td>!</td></tr>
     <tr><td>                        Clang </td><td>  .69 (6.9s) </td><td> .70  (5.1s) </td><td> <i>2.2</i> (19s) </td><td></td>!</tr>
   </tbody>
 </table>

 Radix sorts, for reference
 <table>
   <thead>
     <tr> <th> Variant </th>
       <th> Compiler </th>
       <th> Haswell </th>
       <th> SkylakeX </th>
       <th> Zen2 <br> -march=znver2 </th>
       <th> * </th>
     </tr>
   </thead>
   <tbody>
     <tr><td rowspan=2> RX256</td><td> G++ </td><td> <b>.13</b> (1.3s) </td><td> <b>.14</b> (1.0s) </td><td> <b>.20</b> (1.8s)  </td><td>!</td></tr>
     <tr><td>                        Clang </td><td> <b>.12</b> (1.2s) </td><td> <b>.12</b> (0.9s) </td><td> <b>.21</b> (1.8s)  </td><td>!</td></tr>
     <tr><td rowspan=2> RX2  </td><td> G++ </td><td> .66 (6.7s) </td><td> .62 (4.5s) </td><td> <i>1.4</i> (12.7s)   </td><td></td></tr>
     <tr><td>                        Clang </td><td> .71 (7.1s) </td><td> .66 (4.8s) </td><td> <i>1.4</i> (11.7s) </td><td></td></tr>
   </tbody>
</table>
