subroutine sum_abs(inp, num, suma)
  implicit none
  integer, intent(in) :: inp(*), num
  integer, intent(out) :: suma
  integer :: i,x

   x = 0
   do i=1,num
     x = x + abs(inp(i)); 
   end do
   suma = x;
end subroutine sum_abs
 
