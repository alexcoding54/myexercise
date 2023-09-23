program bubble_sort
    implicit none
    integer, dimension(10) :: array = [9, 5, 2, 7, 1, 8, 3, 6, 4, 0]
    integer :: i, j, temp
    integer :: n = size(array)
  
    ! 执行冒泡排序
    do i = 1, n-1
       do j = 1, n-i
          if (array(j) > array(j+1)) then
             temp = array(j)
             array(j) = array(j+1)
             array(j+1) = temp
          end if
       end do
    end do 
  
    ! 打印排序后的数组
    do i = 1, n
       print *, array(i)
    end do

end program bubble_sort
  