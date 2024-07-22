// dear imgui
// Demo Tests demonstrating the Dear ImGui Test Engine

#define IMGUI_DEFINE_MATH_OPERATORS
#include "imgui.h"
#include "imgui_internal.h"
#include "../deps/imgui_test_engine/imgui_test_engine/imgui_te_context.h"
#include "../deps/imgui_test_engine/imgui_test_engine/imgui_capture_tool.h"

void RegisterAppMinimalTests(ImGuiTestEngine* e)
{
    ImGuiTest* t = NULL;

    t=IM_REGISTER_TEST(e, "demo_test", "Test 1");
	t->TestFunc = [](ImGuiTestContext* ctx)
		{
			int a = 2;
			int b = 3;
			IM_CHECK_EQ(a,2);
			IM_CHECK_EQ(b,3);
			IM_CHECK_EQ(a+b,5);
		};

   t=IM_REGISTER_TEST(e, "demo_test", "Test 2");
   t->TestFunc = [](ImGuiTestContext* ctx)
	   {
		   float a = 3.4;
		   float b = 4.5;
		   IM_CHECK_FLOAT_EQ_EPS(a,3.4);
		   IM_CHECK_FLOAT_EQ_EPS(b,4.5);
		   IM_CHECK_FLOAT_EQ_EPS(a+b,7.9);

	   };
}
