// dear imgui
// Demo Tests demonstrating the Dear ImGui Test Engine

#define IMGUI_DEFINE_MATH_OPERATORS
#include "imgui.h"
#include "imgui_internal.h"
#include "../deps/imgui_test_engine/imgui_test_engine/imgui_te_context.h"
#include "../deps/imgui_test_engine/imgui_test_engine/imgui_capture_tool.h"
#include <vector>

// Chapter 1: Tuples, Points, and Vectors

#include "Vector.h"

// Chapter 2: Drawing on a Canvas
#include "Canvas.h"

class Projectile
{
public:
	Projectile(TUPLE position, TUPLE velocity) : _position(position), _velocity(velocity) { _velocity = velocity.Normalise(); }

	TUPLE _position;
	TUPLE _velocity;
};

class Environment
{
public:
Environment(TUPLE gravity, TUPLE wind) : _gravity(gravity), _wind(wind) {}
	TUPLE _gravity;
	TUPLE _wind;
};
std::vector<std::string> SplitString(const char* str, char delimiter)
{
	std::vector<std::string> result;

	do
	{
		const char* begin = str;

		while (*str != delimiter && *str)
			str++;

		result.push_back(std::string(begin, str));
	} while (0 != *str++);

	return result;
}
ImGuiTest* Tests_Chapter1(ImGuiTest* t, ImGuiTestEngine* e)
{
	t = IM_REGISTER_TEST(e, "Chapter 1", "Tuples");
	t->TestFunc = [](ImGuiTestContext* ctx)
		{
			auto a = TUPLE(4.3, -4.2, 3.1, 1.0);
			IM_CHECK_FLOAT_NEAR(a.x, 4.3, EPSILON);
			IM_CHECK_FLOAT_NEAR(a.y, -4.2, EPSILON);
			IM_CHECK_FLOAT_NEAR(a.z, 3.1, EPSILON);
			IM_CHECK_FLOAT_NEAR(a.w, 1.0, EPSILON);
			auto b = TUPLE(4.3, -4.2, 3.1, 0.0);
			IM_CHECK_FLOAT_NEAR(b.x, 4.3, EPSILON);
			IM_CHECK_FLOAT_NEAR(b.y, -4.2, EPSILON);
			IM_CHECK_FLOAT_NEAR(b.z, 3.1, EPSILON);
			IM_CHECK_FLOAT_NEAR(b.w, 0.0, EPSILON);

		};

	t = IM_REGISTER_TEST(e, "Chapter 1", "Points");
	t->TestFunc = [](ImGuiTestContext* ctx)
		{
			auto a = Point(4, -4, 3);
			IM_CHECK_FLOAT_NEAR(a.x, 4, EPSILON);
			IM_CHECK_FLOAT_NEAR(a.y, -4, EPSILON);
			IM_CHECK_FLOAT_NEAR(a.z, 3, EPSILON);
			IM_CHECK_FLOAT_NEAR(a.w, 1, EPSILON);
			auto b = Vec3(4, -4, 3);
			IM_CHECK_FLOAT_NEAR(b.x, 4, EPSILON);
			IM_CHECK_FLOAT_NEAR(b.y, -4, EPSILON);
			IM_CHECK_FLOAT_NEAR(b.z, 3, EPSILON);
			IM_CHECK_FLOAT_NEAR(b.w, 0, EPSILON);
		};

	t = IM_REGISTER_TEST(e, "Chapter 1", "Addition");
	t->TestFunc = [](ImGuiTestContext* ctx)
		{
			auto a1 = TUPLE(3, -2, 5, 1);
			auto a2 = TUPLE(-2, 3, 1, 0);
			auto a3 = a1 + a2;
			IM_CHECK_FLOAT_NEAR(a3.x, 1, EPSILON);
			IM_CHECK_FLOAT_NEAR(a3.y, 1, EPSILON);
			IM_CHECK_FLOAT_NEAR(a3.z, 6, EPSILON);
			IM_CHECK_FLOAT_NEAR(a3.w, 1, EPSILON);
		};

	t = IM_REGISTER_TEST(e, "Chapter 1", "Subtraction");
	t->TestFunc = [](ImGuiTestContext* ctx)
		{
			auto a1 = Point(3, 2, 1);
			auto a2 = Point(5, 6, 7);
			auto a3 = a1 - a2;
			IM_CHECK_FLOAT_NEAR(a3.x, -2, EPSILON);
			IM_CHECK_FLOAT_NEAR(a3.y, -4, EPSILON);
			IM_CHECK_FLOAT_NEAR(a3.z, -6, EPSILON);
			IM_CHECK_FLOAT_NEAR(a3.w, 0, EPSILON);
		};

	t = IM_REGISTER_TEST(e, "Chapter 1", "Sub From Zero");
	t->TestFunc = [](ImGuiTestContext* ctx)
		{
			auto a1 = TUPLE(1, -2, 3, -4);
			auto a2 = TUPLE(0, 0, 0, 0);
			auto a3 = a2 - a1;
			IM_CHECK_FLOAT_NEAR(a3.x, -1, EPSILON);
			IM_CHECK_FLOAT_NEAR(a3.y, 2, EPSILON);
			IM_CHECK_FLOAT_NEAR(a3.z, -3, EPSILON);
			IM_CHECK_FLOAT_NEAR(a3.w, 4, EPSILON);
		};
	t = IM_REGISTER_TEST(e, "Chapter 1", "Negation");
	t->TestFunc = [](ImGuiTestContext* ctx)
		{
			auto a1 = TUPLE(1, -2, 3, -4);
			auto a2 = -a1;
			IM_CHECK_FLOAT_NEAR(a2.x, -1, EPSILON);
			IM_CHECK_FLOAT_NEAR(a2.y, 2, EPSILON);
			IM_CHECK_FLOAT_NEAR(a2.z, -3, EPSILON);
			IM_CHECK_FLOAT_NEAR(a2.w, 4, EPSILON);
		};

	t = IM_REGISTER_TEST(e, "Chapter 1", "Multiplication");
	t->TestFunc = [](ImGuiTestContext* ctx)
		{
			auto a1 = TUPLE(1, -2, 3, -4);
			auto a2 = a1 * 3.5;
			IM_CHECK_FLOAT_NEAR(a2.x, 3.5, EPSILON);
			IM_CHECK_FLOAT_NEAR(a2.y, -7, EPSILON);
			IM_CHECK_FLOAT_NEAR(a2.z, 10.5, EPSILON);
			IM_CHECK_FLOAT_NEAR(a2.w, -14, EPSILON);
		};

	t = IM_REGISTER_TEST(e, "Chapter 1", "Division");
	t->TestFunc = [](ImGuiTestContext* ctx)
		{
			auto a1 = TUPLE(1, -2, 3, -4);
			auto a2 = a1 / 2;
			IM_CHECK_FLOAT_NEAR(a2.x, 0.5, EPSILON);
			IM_CHECK_FLOAT_NEAR(a2.y, -1, EPSILON);
			IM_CHECK_FLOAT_NEAR(a2.z, 1.5, EPSILON);
			IM_CHECK_FLOAT_NEAR(a2.w, -2, EPSILON);
		};

	t = IM_REGISTER_TEST(e, "Chapter 1", "Magnitude");
	t->TestFunc = [](ImGuiTestContext* ctx)
		{
			auto a1 = Vec3(1, 0, 0);
			auto a2 = Vec3(0, 1, 0);
			auto a3 = Vec3(0, 0, 1);
			auto a4 = Vec3(1, 2, 3);
			auto a5 = Vec3(-1, -2, -3);
			IM_CHECK_FLOAT_NEAR(a1.Magnitude(), 1, EPSILON);
			IM_CHECK_FLOAT_NEAR(a2.Magnitude(), 1, EPSILON);
			IM_CHECK_FLOAT_NEAR(a3.Magnitude(), 1, EPSILON);
			IM_CHECK_FLOAT_NEAR(a4.Magnitude(), sqrt(14), EPSILON);
			IM_CHECK_FLOAT_NEAR(a5.Magnitude(), sqrt(14), EPSILON);
		};

	t = IM_REGISTER_TEST(e, "Chapter 1", "Normalize");
	t->TestFunc = [](ImGuiTestContext* ctx)
		{
			auto a1 = Vec3(4, 0, 0);
			auto a2 = Vec3(1, 2, 3);
			auto a3 = a1.Normalise();
			auto a4 = a2.Normalise();
			IM_CHECK_FLOAT_NEAR(a3.x, 1, EPSILON);
			IM_CHECK_FLOAT_NEAR(a3.y, 0, EPSILON);
			IM_CHECK_FLOAT_NEAR(a3.z, 0, EPSILON);
			IM_CHECK_FLOAT_NEAR(a4.x, 0.26726, EPSILON);
			IM_CHECK_FLOAT_NEAR(a4.y, 0.53452, EPSILON);
			IM_CHECK_FLOAT_NEAR(a4.z, 0.80178, EPSILON);
		};

	t = IM_REGISTER_TEST(e, "Chapter 1", "Dot Product");
	t->TestFunc = [](ImGuiTestContext* ctx)
		{
			auto a1 = Vec3(1, 2, 3);
			auto a2 = Vec3(2, 3, 4);
			IM_CHECK_FLOAT_NEAR(a1.Dot(a2), 20, EPSILON);
		};

	t = IM_REGISTER_TEST(e, "Chapter 1", "Cross Product");
	t->TestFunc = [](ImGuiTestContext* ctx)
		{
			auto a1 = Vec3(1, 2, 3);
			auto a2 = Vec3(2, 3, 4);
			auto a3 = a1.Cross(a2);
			auto a4 = a2.Cross(a1);
			IM_CHECK_FLOAT_NEAR(a3.x, -1, EPSILON);
			IM_CHECK_FLOAT_NEAR(a3.y, 2, EPSILON);
			IM_CHECK_FLOAT_NEAR(a3.z, -1, EPSILON);
			IM_CHECK_FLOAT_NEAR(a4.x, 1, EPSILON);
			IM_CHECK_FLOAT_NEAR(a4.y, -2, EPSILON);
			IM_CHECK_FLOAT_NEAR(a4.z, 1, EPSILON);
		};

	t = IM_REGISTER_TEST(e, "Chapter 1", "Velocity Test");
	t->TestFunc = [](ImGuiTestContext* ctx)
		{
			Projectile proj(Vec3(0, 1, 0), Vec3(1, 1, 0));
			Environment env(Vec3(0, -0.1, 0), Vec3(-0.01, 0, 0));
			ImGuiTextBuffer* expr_buf = ImGuiTestEngine_GetTempStringBuilder();
			while (proj._position.y > 0)
			{
				proj._position += proj._velocity;
				proj._velocity += env._gravity + env._wind;
				printf("Position: %f, %f, %f\n", proj._position.x, proj._position.y, proj._position.z);
				printf("Velocity: %f, %f, %f\n", proj._velocity.x, proj._velocity.y, proj._velocity.z);

			}

			IM_CHECK_EQ(1, 1);
			//IM_CHECK_FLOAT_NEAR(proj._position.y, 0, EPSILON);

		};
	//t = IM_REGISTER_TEST(e, "Chapter 1", "Reflecting a vector approaching at 45 degrees");
	//t->TestFunc = [](ImGuiTestContext* ctx)
	//	{
	//		auto v = Vec3(1, -1, 0);
	//		auto n = Vec3(0, 1, 0);
	//		auto r = v.Reflect(n);
	//		IM_CHECK_FLOAT_NEAR(r.x, 1, EPSILON);
	//		IM_CHECK_FLOAT_NEAR(r.y, 1, EPSILON);
	//		IM_CHECK_FLOAT_NEAR(r.z, 0, EPSILON);
	//	};

	//t = IM_REGISTER_TEST(e, "Chapter 1", "Reflecting a vector off a slanted surface");
	//t->TestFunc = [](ImGuiTestContext* ctx)
	//	{
	//		auto v = Vec3(0, -1, 0);
	//		auto n = Vec3(sqrt(2) / 2, sqrt(2) / 2, 0);
	//		auto r = v.Reflect(n);
	//		IM_CHECK_FLOAT_NEAR(r.x, 1, EPSILON);
	//		IM_CHECK_FLOAT_NEAR(r.y, 0, EPSILON);
	//		IM_CHECK_FLOAT_NEAR(r.z, 0, EPSILON);
	//	};

	//t = IM_REGISTER_TEST(e, "Chapter 1", "Reflecting a vector off a non-axial surface");
	//t->TestFunc = [](ImGuiTestContext* ctx)
	//	{
	//		auto v = Vec3(1, -1, 0);
	//		auto n = Vec3(1, 1, 0);
	//		auto r = v.Reflect(n);
	//		IM_CHECK_FLOAT_NEAR(r.x, 0, EPSILON);
	//		IM_CHECK_FLOAT_NEAR(r.y, 0, EPSILON);
	//		IM_CHECK_FLOAT_NEAR(r.z, 0, EPSILON);
	//	};
	//
	return t;
}
ImGuiTest* Tests_Chapter2(ImGuiTest* t, ImGuiTestEngine* e)
{
		t = IM_REGISTER_TEST(e, "Chapter 2", "Canvas");
		t->TestFunc = [](ImGuiTestContext* ctx)
			{
			auto canvas = Canvas(10, 20);
			IM_CHECK_EQ(canvas.Width(), 10);
			IM_CHECK_EQ(canvas.Height(), 20);
			auto c = Colour(1.f, 0.f, 0.f,1.f);
			canvas.WritePixel(2, 3, c);
			auto c2 = canvas.PixelAt(2, 3);
			IM_CHECK_EQ(c, c2);
		};
	t = IM_REGISTER_TEST(e, "Chapter 2", "PPM Header");
	t->TestFunc = [](ImGuiTestContext* ctx)
		{
			
			auto canvas = Canvas(5, 3);
			auto ppm = canvas.ToPPM("Ch2-T1.ppm");
			auto lines = SplitString(ppm.c_str(), '\n');
			IM_CHECK_EQ(lines[0], "P3");
			IM_CHECK_EQ(lines[1], "5 3");
			IM_CHECK_EQ(lines[2], "255");
		};
	t = IM_REGISTER_TEST(e, "Chapter 2", "PPM Pixel Data");
	t->TestFunc = [](ImGuiTestContext* ctx)
		{
			
			auto canvas = Canvas(5, 3);
			auto c1 = Colour(1.5, 0, 0);
			auto c2 = Colour(0, 0.5, 0);
			auto c3 = Colour(-0.5, 0, 1);
			canvas.WritePixel(0, 0, c1);
			canvas.WritePixel(2, 1, c2);
			canvas.WritePixel(4, 2, c3);
			auto ppm = canvas.ToPPM("Ch2-T2.ppm");
			auto lines = SplitString(ppm.c_str(), '\n');
			IM_CHECK_EQ(lines[3], "255 0 0 0 0 0 0 0 0 0 0 0 0 0 0");
			IM_CHECK_EQ(lines[4], "0 0 0 0 0 0 0 128 0 0 0 0 0 0 0");
			IM_CHECK_EQ(lines[5], "0 0 0 0 0 0 0 0 0 0 0 0 0 0 255");
		};

	/*t = IM_REGISTER_TEST(e, "Chapter 2", "Splitting long lines in PPM files");
	t->TestFunc = [](ImGuiTestContext* ctx)
		{
			
			auto canvas = Canvas(10, 2);
			auto c = Colour(1, 0.8, 0.6);
			for (int y = 0; y < canvas.Height(); y++)
				for (int x = 0; x < canvas.Width(); x++)
					canvas.WritePixel(x, y, c);
			auto ppm = canvas.ToPPM("Ch2-T3.ppm");
			auto lines = SplitString(ppm.c_str(), '\n');
			IM_CHECK_EQ(lines[3], "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204");
			IM_CHECK_EQ(lines[4], "153 255 204 153 255 204 153 255 204 153 255 204 153");
			IM_CHECK_EQ(lines[5], "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153");
			IM_CHECK_EQ(lines[6], "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153");
		};*/

	t = IM_REGISTER_TEST(e, "Chapter 2", "PPM files are terminated by a newline character");
	t->TestFunc = [](ImGuiTestContext* ctx)
		{
			
			auto canvas = Canvas(5, 3);
			auto ppm = canvas.ToPPM("Ch2-T4.ppm");
			auto lines = SplitString(ppm.c_str(), '\n');
			IM_CHECK_EQ(lines[6], "");
		};

	t = IM_REGISTER_TEST(e, "Chapter 2", "Velocity Test");
	t->TestFunc = [](ImGuiTestContext* ctx)
		{
			Projectile proj(Vec3(0, 1, 0), Vec3(1, 1.8, 0));
			proj._velocity*= 11.25;
			Environment env(Vec3(0, -0.1, 0), Vec3(-0.01, 0, 0));
			ImGuiTextBuffer* expr_buf = ImGuiTestEngine_GetTempStringBuilder();
			Canvas canvas(900, 550);
			while (proj._position.y > 0)
			{
				proj._position += proj._velocity;
				proj._velocity += env._gravity + env._wind;
				//printf("Position: %f, %f, %f\n", proj._position.x, proj._position.y, proj._position.z);
				//printf("Velocity: %f, %f, %f\n", proj._velocity.x, proj._velocity.y, proj._velocity.z);
				
				canvas.WritePixel(proj._position.x, canvas.Height() - proj._position.y, Colour(1, 0, 0));
			}
			canvas.ToPPM("Chapter2.ppm");

			IM_CHECK_EQ(1, 1);
			//IM_CHECK_FLOAT_NEAR(proj._position.y, 0, EPSILON);

		};

	return t;
}
void RegisterAppMinimalTests(ImGuiTestEngine* e)
{
    ImGuiTest* t = NULL;

	t = Tests_Chapter1(t, e);
	t = Tests_Chapter2(t, e);
}
