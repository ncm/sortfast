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
       <th> Zen2 (DDR3) </th>
       <th> * </th>
     </tr>
   </thead>
   <tbody>
     <tr><td rowspan=2> STD  </td><td> G++ </td><td> 1 (10.2s) </td><td> 1 (7.3s) </td><td> 1 (9.5s) </td><td></td></tr>
     <tr><td>                        Clang </td><td> 1 (10.0s) </td><td> 1 (7.3s) </td><td> 1 (9.4s) </td><td></td></tr>
     <tr><td rowspan=2> BOG  </td><td> G++ </td><td> 1.1 (11.5s) </td><td> 1.1  (8.2s) </td><td> 1.2 (11s) </td><td></td></tr>
     <tr><td>                        Clang </td><td> 1.1 (11.3s) </td><td> 1.1  (7.9s) </td><td> 1.1 (10.3s) </td><td></td></tr>
     <tr><td rowspan=2> &&|  </td><td> G++ </td><td> .56  (5.7s) </td><td>  .61 (4.5s) </td><td> .89 (8.5s) </td><td></td></tr>
     <tr><td>                        Clang </td><td> <b>.49</b> (4.9s) </td><td> <b> .47</b> (3.4s) </td><td> .65 (6,1s) </td><td></td> ! </tr>
     <tr><td rowspan=2> IX   </td><td> G++ </td><td>  .79 (8.1s) </td><td>  .89 (6.5s) </td><td> .84 (8.0s) </td><td></td></tr>
     <tr><td>                        Clang </td><td>  .66 (6.6s) </td><td>  .63 (4.6s) </td><td> .81 (7.7s) </td><td></td></tr>
     <tr><td rowspan=2> IX-P </td><td> G++ </td><td> 1.2 (12.0s) </td><td>  1.2 (8.4s) </td><td> 1.3 (12.6s) </td><td></td></tr>
     <tr><td>                        Clang </td><td>  .64 (6.4s) </td><td>  .60 (4.4s) </td><td> .77 (7.3s) </td><td></td></tr>
     <tr><td rowspan=2> ROT  </td><td> G++ </td><td> .72  (7.3s) </td><td>  .70 (5.1s) </td><td> .78 (7.4s) </td><td></td></tr>
     <tr><td>                        Clang </td><td>  .68 (6.8s) </td><td>  .66 (4.8s) </td><td> .66 (6.3s) </td><td></td></tr>
     <tr><td rowspan=2> CMOV </td><td> G++ </td><td> 1.1 (11.3s) </td><td>  1.1 (8.0s) </td><td> 1.1 (10.3s) </td><td></td></tr>
     <tr><td>                        Clang </td><td> <b>.49</b> (4.9s)</td><td><b>.47</b> (3.4s) </td><td> .62 (5.9s) </td><td></td> ! </tr>
     <tr><td rowspan=2> IX1  </td><td> G++ </td><td> <i>1.6</i> (15.9s) </td><td> <i>1.6</i> (11.8s) </td><td> <i>1.5</i> (14s) </td><td></td> ! </tr>
     <tr><td>                        Clang </td><td>  .61 (6.1s) </td><td>  .62 (4.5s) </td><td> .65 (6.2s) </td><td></td></tr>
     <tr><td rowspan=2> IX2  </td><td> G++ </td><td> 1.1 (11.2s) </td><td>  1.1 (8.2s) </td><td> <i>1.5</i> (14s) </td><td></td></tr>
     <tr><td>                        Clang </td><td>  .69 (6.9s) </td><td> .70  (5.1s) </td><td> 1.2 (11.7s) </td><td></td></tr>
   </tbody>
 </table>

 Radix sorts, for reference
 <table>
   <thead>
     <tr> <th> Variant </th>
       <th> Compiler </th>
       <th> Haswell </th>
       <th> SkylakeX </th>
       <th> Zen2 (DDR3)</th>
       <th> * </th>
     </tr>
   </thead>
   <tbody>
     <tr><td rowspan=2> RX256</td><td> G++ </td><td> <b>.13</b> (1.3s) </td><td> <b>.14</b> (1.0s) </td><td> <b>.16</b> (1.5s)  </td><td></td>!</tr>
     <tr><td>                        Clang </td><td> <b>.12</b> (1.2s) </td><td> <b>.12</b> (0.9s) </td><td> <b>.18</b> (1.7s)  </td><td></td>!</tr>
     <tr><td rowspan=2> RX2  </td><td> G++ </td><td> .66 (6.7s) </td><td> .62 (4.5s) </td><td> 1.2 (11s)   </td><td></td></tr>
     <tr><td>                        Clang </td><td> .71 (7.1s) </td><td> .66 (4.8s) </td><td> 1.1 (10.9s) </td><td></td></tr>
   </tbody>
</table>
