from django.conf.urls import url
from django.contrib import admin
from .views import ( StudentListAPIView, StudentCreateAPIView
					)



urlpatterns = [
    url(r'^list/$', StudentListAPIView.as_view(), name = 'students-api-list'),
    url(r'^create/$', StudentCreateAPIView.as_view(), name = 'students-api-create'),

    # url(r'^(?P<slug>[\w-]+)/$', StudentInfoDetailView.as_view(), name = 'students-api-detail'),
    # url(r'^(?P<slug>[\w-]+)/update/$', StudentInfoUpdateAPIView.as_view(), name = 'students-api-update'),
    # url(r'^(?P<slug>[\w-]+)/delete/$', StudentInfoDeleteAPIView.as_view(), name = 'students-api-delete'),
    


]
