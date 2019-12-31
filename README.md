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
     </tr>
   </thead>
   <tbody>
     <tr><td rowspan=2> STD  </td><td> G++ </td><td> 10.2 </td><td>  7.3 </td></tr>
     <tr><td>                        Clang </td><td> 10.0 </td><td>  7.3 </td></tr>
     <tr><td rowspan=2> BOG  </td><td> G++ </td><td> 11.5 </td><td>  8.2 </td></tr>
     <tr><td>                        Clang </td><td> 11.3 </td><td>  7.9 </td></tr>
     <tr><td rowspan=2> &&|  </td><td> G++ </td><td>  5.7 </td><td>  4.5 </td></tr>
     <tr><td>                        Clang </td><td> <em>4.9</em> </td><td> <em>3.4</em> </td></tr>
     <tr><td rowspan=2> IX   </td><td> G++ </td><td>  8.1 </td><td>  6.5 </td></tr>
     <tr><td>                        Clang </td><td>  6.6 </td><td>  4.6 </td></tr>
     <tr><td rowspan=2> IX-P </td><td> G++ </td><td><b>12.0</b></td> <td><b>8.4</b> </td></tr>
     <tr><td>                        Clang </td><td>  6.4 </td><td>  4.4 </td></tr>
     <tr><td rowspan=2> ROT  </td><td> G++ </td><td>  7.3 </td><td>  5.1 </td></tr>
     <tr><td>                        Clang </td><td>  6.8 </td><td>  4.8 </td></tr>
     <tr><td rowspan=2> CMOV </td><td> G++ </td><td> 11.3 </td><td>  8.0 </td></tr>
     <tr><td>                        Clang </td><td>  4.9 </td><td>  3.4 </td></tr>
     <tr><td rowspan=2> IX1  </td><td> G++ </td><td><b>22.6</b></td> <td> <b>15.8</b> </td></tr>
     <tr><td>                        Clang </td><td>  6.1 </td><td>  4.2 </td></tr>
     <tr><td rowspan=2> IX2  </td><td> G++ </td><td><b>19.3<b></td> <td> <b>13.5</b> </td></tr>
     <tr><td>                        Clang </td><td>  6.9 </td><td>  4.8 </td></tr>
   </tbody>
 </table>
 
 Radix sorts, for reference
 <table>
   <thead>
     <tr> <th> Variant </th>
       <th> Compiler </th>
       <th> Haswell </th>
       <th> SkylakeX </th>
     </tr>
   </thead>
   <tbody>
     <tr><td rowspan=2> RX256</td><td> G++ </td><td>  1.3 </td><td>  1.0 </td></tr>
     <tr><td>                        Clang </td><td>  1.2 </td><td>  0.9 </td></tr>
     <tr><td rowspan=2> RX2  </td><td> G++ </td><td>  6.7 </td><td>  4.5 </td></tr>
     <tr><td>                        Clang </td><td>  7.1 </td><td>  4.8 </td></tr>
   </tbody>
</table>
