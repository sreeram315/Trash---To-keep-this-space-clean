from django.shortcuts import render
from django.views.generic import TemplateView, ListView

from students.models import StudentInfo

# Create your views here.


class HomeView(TemplateView):
	template_name = 'home.html'

class StudentList(ListView):
	template_name = 'list.html'

	def get_queryset(request, *args, **kwargs):
		qs = StudentInfo.objects.all()
		return qs

class StudentCreateView(TemplateView):
	template_name = 'create.html'
