with my_cpp_function_h;
with Ada.Text_IO;
with Interfaces.C;

procedure my_func_test is
   cls : aliased my_cpp_function_h.Class_cls.cls :=  my_cpp_function_h.Class_cls.New_cls;
   input_value : Interfaces.C.int;
   function_return_value : Interfaces.C.int;
begin
    input_value := 42;
    function_return_value := my_cpp_function_h.Class_cls.my_method (Cls'Access, input_value);

    Ada.Text_IO.Put_Line(Function_Return_Value'Image);

end my_func_test;
